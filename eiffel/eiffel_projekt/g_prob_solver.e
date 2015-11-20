note
	description: "Summary description for {G_PROB_SOLVER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	G_PROB_SOLVER
create
	accessFaculty , accessTree
feature
	copyoftree : detachable TREES
feature
	accessFaculty(i : INTEGER)
	do
		calculate(i)
	end

feature
	accessTree(i : INTEGER ; copyTree : TREES)
	do
		trytofindint(i , copyTree)
	end

feature
	firstCalc:BOOLEAN
	tempF:INTEGER

feature{NONE}
fac_q1 : FAC_PROBLEM_Q
	once
		create {FAC_PROB_Q2}Result.calculation(0,firstCalc,0)
	ensure
		fac_q1_exists: Result /= Void
	end

	write(name : STRING; f : INTEGER)
	do
		io.put_string ("fac_" + name + "(" + f.out + ") = " +fac_q1.out)
		io.put_new_line
	end

	calculate(i: INTEGER)
		local
			f : INTEGER

			do
			f := i
			if (f < 32 AND f>0)then

			firstCalc:=true
			fac_q1.calculation(f,firstCalc,tempF)
       		write("ERGEBNIS = ",fac_q1.solution.tempf)
			io.put_new_line
			else
				print("Fakultatsbereich falsch %N")
			end
		end


feature{NONE}
	searching_q2 : SEARCH_PROBLEM_Q
	once
		create {SEARCH_PROB_Q2}Result.searching(0,0)
	ensure
		searching_q2_exists: Result /= Void
	end

	trytofindint(i: INTEGER ; temptree : TREES)
		local
			f : INTEGER
			n : INTEGER
			yeah : INTEGER
		do
			if(i<=0)then
				print("zahl auserhalb des bereichs %N")
			else
			copyoftree := temptree
			n := temptree.node.getvalue
			f := i
			print("F  " + f.out + "%N")
			yeah := findnumber(f, temptree.node)
			if (yeah <= 0) then
				print("Zahl nicht im baum %N")
			else
			searching_q2.searching (f, yeah)
       		write("INTEGER IN TREE = ",searching_q2.solution.searchint)
       	--	print("ERGEBNIS = " +fac_q1.solution.fac)
			--io.put_new_line
			print("started the tree as searching")
			end
			end
		end

feature
	findnumber(d : INTEGER; knot : NODE) :INTEGER
	do
		if(d = knot.getvalue) then
			print("erste node im tree %N")
			result := d
		elseif(d < knot.getvalue) then
			if attached knot.getleft as okNode then
				print("nächste node im tree %N")
				Result := findnumber(d,okNode)
			end
		elseif(d > knot.getvalue) then
			if attached knot.getright as okNode then
				Result := findnumber(d,okNode)
		elseif (d /= knot.getvalue)then
			Result := -1
			end
		end
	end
end
