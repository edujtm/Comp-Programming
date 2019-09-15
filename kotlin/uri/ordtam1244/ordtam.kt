
val input = System.`in`.bufferedReader()

fun readln() = input.readLine()!!
fun readlnInt() = readln().toInt()

fun readlnStrings() = readln().split(' ')

fun main(args: Array<String>) {
    val tests = readlnInt()
    for (i in 1..tests) {
        val strings : List<String> = readlnStrings()  
        val sorted = strings.sortedWith(compareByDescending({ it.length }))
        println(sorted.joinToString(separator=" "))
    }
}