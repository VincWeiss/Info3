note
	description: "Summary description for {PROBLEM}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	PROBLEM[S]

feature
	solution : S
	deferred
	ensure
		solution_exists: Result /= Void
	end
end
