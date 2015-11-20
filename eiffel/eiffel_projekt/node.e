note
	description: "Summary description for {NODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	NODE

create
	make

feature -- Initialization
	value : INTEGER;
	left : detachable NODE;
	right : detachable NODE;
	parent : detachable NODE;
	--counter : INTEGER
	--marked : BOOLEAN;

feature{TREES} --Constructor Sets the Parent of the NODE and the content(value) of the NODE
	make(val : INTEGER; nodeParent : detachable NODE)
	do
		setValue(val)
		setparent(nodeParent)
	end

feature --Getter/Setter left	
	getLeft : detachable NODE
	do
		Result := left
	ensure
		Result = left
	end

	setLeft(leftNode : detachable NODE)
	do
		left := leftNode
	ensure
		left = leftNode
	end

feature --Getter/Setter rigth	
	getRight : detachable NODE
	do
		Result := right
	ensure
		Result = right
	end

	setRight(rightNode : detachable NODE)
	do
		right := rightNode
	ensure
		right = rightNode
	end

feature --Getter/Setter parent
	getParent : detachable NODE
	do
		Result := parent
	ensure
		Result = parent
	end

	setParent(parentNode : detachable NODE)
	do
		parent := parentNode
	ensure
		parent = parentNode
	end

feature --Getter/Setter Value
	getValue : INTEGER
    do
    	Result :=  value
    ensure
    	Result = value
    end

    setValue(val : INTEGER)
	do
		value := val
	ensure
		value = val
	end
end

