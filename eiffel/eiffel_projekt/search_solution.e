note
	description: "Summary description for {SEARCH_SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	SEARCH_SOLUTION
create
	{SEARCH_PROBLEM_Q}searching

feature
	searchint : INTEGER
	compareint : INTEGER

feature{SEARCH_PROBLEM_Q}
	searching(new_searchint , new_compareint : INTEGER)
	require
		argument_nonnegative : new_searchint >= 0
		argument_nonnegative : new_compareint >=0
	do
		searchint := new_searchint
		compareint := new_compareint
	ensure
		argument_accepted: searchint = new_searchint
		argument_accepted: compareint = new_compareint
	end
invariant
	searchint_valid : searchint >= 0
	compareint_valid : compareint >= 0
end
