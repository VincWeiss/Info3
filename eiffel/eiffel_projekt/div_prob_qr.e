note
	description: "Summary description for {DIV_PROB_QR}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	DIV_PROB_QR[S]
		inherit
			DIV_PROB_Q[S]
feature
	solution : S
		do
			if directly_solvable then
				Result := direct_solution
			else
				Result := part.solution
			end
	end -- solution
end
