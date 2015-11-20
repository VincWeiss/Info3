note
	description: "Summary description for {DIV_PROB_Q}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	DIV_PROB_Q[S]
	inherit
		PROBLEM[S]

feature {DIV_PROB_Q}
	directly_solvable : BOOLEAN
		deferred
		end
	direct_solution : like solution
		require
			simple_case: directly_solvable
		deferred
		ensure
			dircect_solution_exists: Result /= Void
		end
	part : like Current
		require
			recursive_case: not directly_solvable
		deferred
		ensure
			part_exists: Result /= Void
		end
end

