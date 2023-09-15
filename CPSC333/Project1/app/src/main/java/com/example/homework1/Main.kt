package com.example.homework1

import kotlin.system.exitProcess

class Game
{
    private val usedNumMap = mutableMapOf<Int,Int>()
    private val ranks = mutableMapOf<Int, Int>()
    private var tmpMap = mutableMapOf<Int, Int>()
    private var turn : Int

    init
    {
        for(count in 1 .. 10)
            ranks[count] = -1
        turn = 10
    }

    fun mainGame()
    {
        while(turn != 0)
        {
            startTurn()
        }
        if(!isSorted())
        {
            println("You lost, the number you placed wasn't in ascending order")
            exitProcess(0)
        }
        println("Congrats, you won!")

    }

    private fun startTurn()
    {
        var num = randomNumGen()
        println("Remaining Placements: $turn")
        println("Generated num: $num")
        println(toString())
        print("Choose a ranking (1-10) or 'q' to quit: ")
        var input = userInput(num)
        ranks[input] = num
        turn--
    }

    private fun userInput(num: Int) : Int
    {
        var input = readln()
        val regex = "^[A-Za-z]*$".toRegex()
        while(true)
        {
            if(input == "q")
                exitProcess(0)
            else if (regex.matches(input))
            {
                println("Please put in a valid input. Either a rank" +
                        "1-10 or q if you would like to quit: ")
                input = readln()
            }
            else if(!validRankInput(input!!.toInt(), num))
            {
                println("Please put a valid rank position. The rank" +
                        "you entered is unavailable")
                input = readln()
            }
            else
                break
        }
        return input!!.toInt()
    }

    //Checks to see if the
    private fun validRankInput(rank: Int, num: Int) : Boolean
    {
        if(rank > 10 || rank < 0)
            return false
        if(ranks[rank] == -1)
        {
            if(isValidPlacement(rank, num))
                return true
        }
        return false
    }

    override fun toString(): String
    {
        var str : String = ""
        for(count in 1 ..10)
        {
            str += "Rank ${count}: "
            if(ranks[count] == -1)
                str += "-\n"
            else
                str += "${ranks[count]}\n"
        }

        return str
    }

    private fun randomNumGen() : Int
    {
        var num = (0..999).random()
        while(randomNumCheck(num))
        {
            num = (0..999).random()
        }
        usedNumMap[num] = 1 //using 1 to denote that one exists
        return num
    }

    private fun randomNumCheck(num: Int) : Boolean
    {
        if(usedNumMap.containsKey(num))
            return true
        return false
    }

    private fun isSorted() : Boolean
    {
        var isBiggest = -1
        for(count in 1 .. 10)
        {
            if(ranks[count] != -1 && isBiggest == -1)
                isBiggest = ranks[count]!!
            else if(isBiggest > ranks[count]!! && ranks[count] != -1)
                return false
            else if(isBiggest < ranks[count]!! && ranks[count] != -1)
                isBiggest = ranks[count]!!
        }
        return true
    }

    private fun isMapSorted() : Boolean
    {
        var isBiggest = -1
        for(count in 1 .. 10)
        {
            if(tmpMap[count] != -1 && isBiggest == -1)
                isBiggest = tmpMap[count]!!
            else if(isBiggest > tmpMap[count]!! && tmpMap[count] != -1)
                return false
            else if(isBiggest < tmpMap[count]!! && tmpMap[count] != -1)
                isBiggest = tmpMap[count]!!
        }
        return true
    }
    private fun isValidPlacement(num: Int, rank: Int) : Boolean
    {

        if(turn == 10)
            return true
        tmpMap = ranks
        tmpMap[rank] = num
        if(isMapSorted())
            return true
        return false
    }

}


fun main()
{
    val game = Game()
    game.mainGame()
}



