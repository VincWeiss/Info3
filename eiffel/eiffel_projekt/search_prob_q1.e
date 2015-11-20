note
	description: "Summary description for {SEARCH_PROB_Q1}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SEARCH_PROB_Q1
		inherit
			SEARCH_PROBLEM_Q
		    TREES

create
	searching
	
feature
	myvalue(input : INTEGER)
		do
			nodeval := input
		end

feature{SEARCH_PROB_Q1}
	directly_solvable : BOOLEAN
		do
			if (node.getValue = nodeval) then
				Result := node.getvalue = nodeval
			end
		end

	direct_solution: like solution
		do
			create Result.searching(nodeval)
		end

	part : like current
		do
			if(nodeval < node.getValue) then
				if attached node.getleft as okNode then
					create Result.searching(okNode.getValue)
				end
			end
			if(nodeval > node.getValue) then
				if attached node.getright as okNode then
					create Result.searching(okNode.getValue)
				end
			end
			create Result.searching(node.getvalue)
		end

end--class end
