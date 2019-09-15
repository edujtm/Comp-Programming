import kotlin.math.*

val input = System.`in`.bufferedReader()

fun readln() = input.readLine()!!
fun readlnInt() = readln().toInt()

fun readlnStrings() = readln().split(' ')
fun readlnIntArray() = readlnStrings().run { IntArray(size) { get(it).toInt() } }

fun main(args: Array<String>) {
    var size = readlnInt()
    while (size != 0) {
        val qnts = readlnIntArray()
        var sum = 0L
        var current = qnts[0].toLong()
        for ((idx, wine) in qnts.withIndex()) {
            if (idx != 0) current += wine
            if (idx != qnts.size - 1)sum += current.absoluteValue
        }
        println(sum)
        size = readlnInt()
    }
}