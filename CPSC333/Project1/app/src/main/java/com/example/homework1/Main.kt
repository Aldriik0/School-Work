package com.example.homework1

import kotlin.random.Random

class Game
{
    private val usedNumMap = mutableMapOf<Int,Int>()
    private val ranks = mutableListOf<MutableList<Int>>()
    init
    {
        for(count in 1 .. 10)
            ranks[count-1][0] = count
    }

    fun mainGame()
    {

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
        val array = removeBlanks()
        for(i in 0 until array.size-1)
        {
            if(array[i] > array[i+1])
                return false
        }
        return true
    }

    private fun removeBlanks() : IntArray
    {
        var array = intArrayOf()
        for(count in 0 until ranks.size)
            if(ranks[count][1] != null)
                array.plus(ranks[count][1])
        return array
    }
}
fun main()
{
    val game = Game()
    game.mainGame()
}



