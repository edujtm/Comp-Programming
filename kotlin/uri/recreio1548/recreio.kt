val input = System.`in`.bufferedReader()

private fun readln() = input.readLine()!!
private fun readlnInt() = readln().toInt()
private fun readlnStrings() = readln().split(' ')
private fun readIntList() = readlnStrings().run { List(size) { get(it).toInt() } }

class Output {
    val outputSb = StringBuilder()
    fun print(o: Any?) { outputSb.append(o) }
    fun println() { outputSb.append('\n') }
    fun println(o: Any?) { outputSb.append(o).append('\n') }
    fun iprintln(o: Any?) { kotlin.io.println(o) } // immediate println for interactive
}

inline fun output(block: Output.()->Unit) { val o = Output().apply(block); print(o.outputSb) }

fun main(args: Array<String>) {
    val tests = readlnInt() 

    for (test in 0..tests-1) {
        val ngrades = readlnInt()
        val grades = readIntList()

        val sorted = grades.sortedDescending()

        var total = 0
        for ((grade, sgrade) in grades.zip(sorted)) {
            if (grade == sgrade) {
                total += 1
            }
        }
        output {
            println(total)
        }
    }
}