note
	description: "Summary description for {SEARCH_PROB_Q1}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SEARCH_PROB_Q2
		inherit
			SEARCH_PROBLEM_Q
			G_PROB_SOLVER

create
	searching
feature
	tocompare : INTEGER
	t : detachable TREES

feature{SEARCH_PROB_Q2}
	directly_solvable : BOOLEAN
		do
			Result := nodeval = intvalue
		end

	direct_solution: like solution
		do
			create Result.searching(nodeval, intvalue)
		end

	part : like current
		do
			create Result.searching(nodeval,intvalue)
		end

end--class end
