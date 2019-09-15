
val input = System.`in`.bufferedReader()

fun readln() = input.readLine()!!
fun readlnStrings() = readln().split(' ')
fun readlnTriple() = input.readLine()
                        ?.split(' ')
                        ?.map { it.toInt() }
                        ?.run { Triple(this[0], this[1], this[2]) } 

fun main(args: Array<String>) {
    var triple = readlnTriple()
    while (triple != null) {
        val (numwords, maxPage, maxLine) = triple
        val words = readlnStrings()
        var (lsize, psize, pages) = Triple(0, 0, 1)
        for (word in words) {
            if (lsize + word.length > maxLine) {
                psize++ 
                lsize = word.length + 1
            } else {
                lsize += word.length + 1
            }

            if (psize == maxPage) {
                pages++
                psize = 0 
            }
        }
        println(pages)
        triple = readlnTriple()
    }
}