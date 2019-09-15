val input = System.`in`.bufferedReader()

fun readln() = input.readLine()!!
fun readlnInt() = readln().toInt()

fun readlnStrings() = readln().split(' ')
fun readlnIntArray() = readlnStrings().run { IntArray(size) { get(it).toInt() } }

class Output {
    val outputSb = StringBuilder()
    fun print(o: Any?) { outputSb.append(o) }
    fun println() { outputSb.append('\n') }
    fun println(o: Any?) { outputSb.append(o).append('\n') }
    fun iprintln(o: Any?) { kotlin.io.println(o) } // immediate println for interactive
}

inline fun output(block: Output.()->Unit) { val o = Output().apply(block); print(o.outputSb) }

const val MAX_HEIGHT = 230

fun main(args: Array<String>) {
    val tests = readlnInt()
    for (i in 1..tests) {
        val population = readlnInt() 
        val heights = readlnIntArray().toList()
        val sorted = bucketSort(heights, MAX_HEIGHT+1)
        output {
            println(sorted.joinToString(separator=" "))
        }
    }
}

fun bucketSort(values: List<Int>, max: Int) : List<Int> {
    val buckets = MutableList<Int>(max) { 0 }
    val sorted = arrayListOf<Int>()
    for (value in values) {
        buckets[value]++
    }
    for ((value, bucket) in buckets.withIndex()) {
        repeat(bucket) {
            sorted.add(value)
        }
    }
    return sorted
}
