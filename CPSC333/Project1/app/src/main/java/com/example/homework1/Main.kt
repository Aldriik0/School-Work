package com.example.homework1

import kotlin.random.Random
import kotlin.system.exitProcess

class Game
{
    private val usedNumMap = mutableMapOf<Int,Int>()
    private val ranks = mutableMapOf<Int, Int>()
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
            if(!isSorted())
            {
                println("You lost, the number you placed wasn't in ascending order")
                exitProcess(0)
            }
        }
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
            else if(!validRankInput(input!!.toInt()))
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

    private fun validRankInput(rank: Int) : Boolean
    {
        if(rank > 10 || rank < 0)
            return false
        if(ranks[rank] == -1)
            return true
        return false
    }


    private fun checkValidSpots(num: Int) : Int
    {
        var lowestAvailableRank = 1
        var ptr = 1
        while(true)
        {
            if(ranks[ptr]!! > num)
                return lowestAvailableRank - 1
            if(lowestAvailableRank == 11)
                return 10
            if(ranks[ptr]!! < num || ranks[ptr]!! != -1)
                ptr++
            else
            {
                lowestAvailableRank++
                ptr++
            }
        }
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
        var num : List<Int> = List(1){ Random.nextInt(0,999)}
        while(randomNumCheck(num[0]))
        {
            num = List(1){Random.nextInt(0,999)}
        }
        usedNumMap[num[0]] = 1 //using 1 to denote that one exists
        return num[0]
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



}
fun main()
{
    val game = Game()
    game.mainGame()
}



