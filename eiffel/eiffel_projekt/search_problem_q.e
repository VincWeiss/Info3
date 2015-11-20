note
	description: "Summary description for {SEARCH_PROBLEM_Q}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SEARCH_PROBLEM_Q
		inherit
			DIV_PROB_QR[SEARCH_SOLUTION]

feature
	nodeval : INTEGER
	intvalue : INTEGER
	searching(new_nodeval, new_intvalue : INTEGER)
		do
			nodeval := new_nodeval
			intvalue := new_intvalue
		ensure
			new_nodeval_accepted : nodeval = new_nodeval
			new_intvalue_accepted : intvalue = new_intvalue
		end
invariant
	searchint_bounded_by_nodeval: nodeval /= 0 implies solution.searchint <= nodeval
	searchint_bounded_by_intvalue: intvalue /= 0 implies solution.searchint <= intvalue
end
