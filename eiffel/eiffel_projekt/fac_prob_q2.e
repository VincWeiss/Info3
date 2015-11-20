note
	description: "Summary description for {FAC_PROB_Q2}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	FAC_PROB_Q2
	inherit
		FAC_PROBLEM_Q
create
	calculation
feature

feature{FAC_PROB_Q2}
	directly_solvable : BOOLEAN
		do
			if (firstcalculation = true AND f = 1) then
			tempF:=f
			end
			Result := f <= 1
		end

	direct_solution : like solution
		do
			create Result.calculation(f,firstcalculation,tempF)
		end

	part : like Current
	do
		if(firstCalculation=true) then
			tempF:=f*(f-1)
			f:=f-1
			firstCalculation:=false
			else
				tempf:=tempF*(f-1)
				f:=f-1
		end
		create Result.calculation(f,firstcalculation,tempF)
	end

end
