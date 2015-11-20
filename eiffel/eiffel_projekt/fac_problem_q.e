note
	description: "Summary description for {FAC_PROBLEM_Q}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	FAC_PROBLEM_Q
		inherit
			DIV_PROB_QR[FAC_SOLUTION]
feature
	f : INTEGER
	firstcalculation:BOOLEAN
	tempF:INTEGER
	calculation(new_f : INTEGER; new_firstcalculation:BOOLEAN;new_tempF:INTEGER)
		do
			f := new_f
			firstcalculation:= new_firstcalculation
			tempF:=new_tempF
		ensure
		new_f_accepted: f = new_f
		new_firstcalculation_accepted : firstcalculation = new_firstcalculation
		new_tempF_accepted: tempF = new_tempF
		end
--invariant
--	fac_bounded_by_f: f /= 0 implies solution.fac <= f.abs

end

