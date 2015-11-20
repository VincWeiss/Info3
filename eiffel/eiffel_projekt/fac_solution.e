note
	description: "Summary description for {FAC_SOLUTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	FAC_SOLUTION
create
	{FAC_PROBLEM_Q}calculation

feature
	fac : INTEGER
	firstcalculation: BOOLEAN
	tempF:INTEGER

feature{FAC_PROBLEM_Q}
	calculation(new_fac : INTEGER; new_firstcalculation : BOOLEAN; new_tempF : INTEGER)
		require
			argument_nonnegative: new_fac >= 0
		do
			fac := new_fac
			firstcalculation := new_firstcalculation
			tempF := new_tempF
		ensure
			argument_accepted: fac = new_fac
			argument_accepted: firstcalculation = new_firstcalculation
			argument_accepted:tempF = new_tempF
		end
invariant
	fac_valid: fac >= 0
end
