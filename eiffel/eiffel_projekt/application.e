note
	description : "test_binary_tree application root class"
	date        : "$Date$"
	revision    : "$Revision$"

class
	APPLICATION

inherit
	ARGUMENTS

create
	make

feature -- Initialization
	test : INTEGER;
	tree : TREES;
	res : BOOLEAN;
	res2 : BOOLEAN;
	gps:G_PROB_SOLVER;

--feature{NONE}
--	fac_q1 : FAC_PROBLEM_Q
--	once
--		create {FAC_PROB_Q1}Result.calculation(0)
--	ensure
--		fac_q1_exists: Result /= Void
--	end
--
--	write(name : STRING; f : INTEGER)
--	do
--		io.put_string ("fac_" + name + "(" + f.out + ") = " +fac_q1.out)
--		io.put_new_line
--	end
--
---	calculation
--		local
--			f : INTEGER
--			do
--			f := 5
--			fac_q1.calculation(f)
  --      	write("STRING NAME",f)
	--		io.put_new_line
	--	end

feature{ANY}
	make
		do
			create tree.make(3)
			tree.insert(2)
			tree.insert (1)
			tree.insert (4)
			tree.insert (6)
			tree.insert (5)
			tree.insert (20)

			res := tree.hasElement(15)
			print("dcfvgbhn exist: " + res.out)
			io.new_line
			res := tree.hasElement(5)
			print("5 exist: " + res.out)
			io.new_line
			res := tree.hasElement(20)
			print("20 exist: " + res.out)
			io.put_new_line

			print("PENIS und HODENSACK")
			io.put_new_line


			--tree.delete (15)
			--tree.delete (5)
			--tree.delete (20)
			--tree.delete (17)
			io.new_line

			res2 := tree.hasElement(15)
			print("15 exist: " + res2.out)
			io.new_line
			res2 := tree.hasElement(5)
			print("5 exist: " + res2.out)
			io.new_line
			res2 := tree.hasElement(20)
			print("20 exist: " + res2.out)
			io.new_line

			--tree.delete (10)
			res2 := tree.hasElement(10)
			print("10 exist: " + res2.out)

			print("FAC Q1 noch nicht aufgerufen" + "%N")
			print("10 exist: " + res2.out)

			io.put_new_line
			print("FAC Q1 noch nicht aufgerufen" + "%N")
			--create gps.go(1)
			--create gps.go(2)
			--create gps.go(3)
			--create gps.go(4)
			create gps.accessTree(2, tree)
			create gps.accessTree(15, tree)
			create gps.accessTree(20, tree)
			--create gps.accessfaculty (-5)
			--print("FAC Q1 noch nicht aufgerufen" + "%N")

		end
end

