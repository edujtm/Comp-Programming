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

data class Team(val number: Int = 0, var points: Long = 0, var made: Long = 0, var received: Long = 0) : Comparable<Team> {

    val avg : Double
        get() = if (this.received == 0L) this.made.toDouble() else (this.made / this.received).toDouble()

    override fun compareTo(other: Team) : Int {
        return when {
            this.points > other.points -> -1
            this.points < other.points -> 1
            this.avg > other.avg -> -1
            this.avg < other.avg -> 1
            this.made > other.made -> -1
            this.made < other.made -> 1
            this.number > other.number -> -1
            this.number < other.number -> 1
            else -> -1 
        }
    }
}

fun main(args: Array<String>) {
    var nteams = readlnInt()
    var current = 1
    while (nteams != 0) {
        if (current != 1)
            println()
        val teams = Array<Team>(nteams) { Team(number=it+1) }
        val nmatches = nteams * (nteams - 1) / 2
        for (i in 1..nmatches) {
            val input = readlnIntArray() 
            calcResults(teams, input)
        }

        val output = teams.sorted().map { it.number }.joinToString(separator=" ")
        output {
            println("Instancia ${current}")
            println(output)
        }

        nteams = readlnInt()
        current++
    } 
}

fun calcResults(teams: Array<Team>, input: IntArray) {
    val teamA = input[0] - 1
    val pointA = input[1]
    val teamB = input[2] - 1
    val pointB = input[3]

    teams[teamA].points += if (pointA > pointB) 2 else 1 
    teams[teamB].points += if (pointA <= pointB) 2 else 1 
    teams[teamA].received += pointB
    teams[teamB].received += pointA
    teams[teamA].made += pointA
    teams[teamB].made += pointB
}