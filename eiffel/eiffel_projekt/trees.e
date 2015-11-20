note
	description: "Summary description for {TREES}."
	date: "$Date$"
	revision: "$Revision$"

class
	TREES

create
		make

feature -- Initialization
	node : NODE;

feature
-- Constructor creates the Tree
	make(i : INTEGER)
		do
			create	node.make(i, Void)
		end

feature
--if the node /= Void then start the InsertFunction
	var:INTEGER
	insert(i : INTEGER)
--require
	--	i.abs >= 0

	do

		var:=i.abs
		if(i<0)then
			print("Illegal Argument " + i.out + "%N")
			end
		if attached Current.node as okNode then
			insertFunction(okNode, var)
		end
	ensure
		haselement (i)
	end

feature{TREES}
	--
	insertFunction(n : NODE; i : INTEGER)
	require
		i.abs >= 0
	local tmpNode : NODE
		do

			if(i=n.getvalue)then
                	print(i.out+" Value is already in tree %N")
                	else
                if (i < n.getValue) then
                	if attached n.getLeft as okNode then
						insertFunction(okNode, i)
                    else
                        create tmpNode.make(i,n)
                        n.setLeft( tmpNode);
                    end
                end
                if (i > n.getValue) then
                	if attached n.getright as okNode then
                        insertFunction(okNode, i);
                    else
                        create tmpNode.make(i,n)
                        n.setRight( tmpNode );
                    end
                end
                end

        ensure
        	haselement (i) = true
        end

feature
	--if the node /= void then start the hasElementFunction
	hasElement(i : INTEGER) : BOOLEAN
	require
		i.abs >= 0
	do
		if attached current.node as okNode then
			Result := hasElementFunction(i, okNode)
		end
	end

feature {NONE}
--
	hasElementFunction(i : Integer; root : NODE) : BOOLEAN
	require
		i.abs >= 0
		root /= Void
		do
		    	if (i = root.getvalue) then
                	Result := true
			  	elseif (i < root.getValue) then
                	if attached root.getLeft as okNode then
						Result := hasElementFunction(i, okNode)
                    end
                elseif (i > root.getValue)then
                	if attached root.getright as okNode then
                        Result := hasElementFunction(i, okNode)
                    end
                end
		end

feature
	delete(i : INTEGER)
	require
		i.abs >= 0
	do
		if attached current.node as okNode then
			deleteFunction(i, okNode)
		end
	ensure
		hasElement(i) = False
	end

feature{NONE}
	--
	deleteFunction(i: INTEGER; root : NODE)
	require
		i.abs >= 0
		root /= Void
	local tmpNode : detachable NODE smallNode : detachable NODE
	do
    --IF the Value to Delete is the first Leave on the left side
    --and this leave has no other leaves
    --delete it
		if attached root.getLeft as okNode1 then
				if( okNode1.getValue = i and okNode1.getleft = Void and okNode1.getright = void)then
			        root.setParent(Void)
			        root.setLeft (Void)
			       end
		end
	--IF the Value to Delete is the first Leave on the right side
    --and this leave has no other leaves
    --delete it
		if attached root.getRight as okNode2 then
				if( okNode2.getValue = i and okNode2.getleft = Void and okNode2.getright = void)then
			        root.setParent(Void)
			        root.setRight (Void)
			       end
		end


	--IF the root Value is I and there is no other leave delete/or set the main tree = void
		if( i = root.getValue and root.getright = Void and root.getleft = Void)then
			root.setvalue (0)
			--remove(root)Only works with Integer ?!
    	elseif (i < root.getValue) then
    	--IF i < root.getValue is the value(i) on the left side of the tree then go in this node
        	if attached root.getleft as okNode then
				deleteFunction(i, okNode)
			end
    	else
    	--Is the Value bigger than the root node
        	if (i > root.getValue) then
        		--Search in the right part of the tree
             	if attached root.getRight as okNode then
					deleteFunction(i, okNode)
				end
         	else --The node to be deleted have been found
         	--the Node to be deleted has only a left Leave         	
            	if (root.getleft = Void) then
                	if attached root.getRight as okNode5 then
						root.setValue(okNode5.getValue)
						root.setParent(okNode5.getParent)
						root.setLeft (okNode5.getLeft)
						root.setRight(okNode5.getRight)
						okNode5.setValue(0)
					end
             	else -- Node to be deletet has no right Leave
                	if (root.getright = Void) then
                		if attached root.getLeft as okNode then
							root.setValue(okNode.getValue)
							root.setParent (okNode.getParent)
							root.setLeft (okNode.getLeft)
							root.setRight(okNode.getRight)
						end
               		else -- there are two children
               		--Search the smallest child from the node to be deleted
                		if attached root.getRight as okNode then
                			if attached root.getleft as okNode2 then
                				if(okNode.getValue < okNode2.getValue) then
                					smallNode := root.getLeft
                				elseif(okNode.getValue > okNode.getValue)then
                					smallNode := root.getRight
                				else
                					smallNode := root
                				end
                			end
						end
			--HIER MUSS GLAUB ICH SMALLNODE REIN ICH PROBIERE DAS GERADE AUS같!같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같
                  		if (tmpNode = root) then --No node have been found
						--Change the Node to delete with the smallest child
						--Node has been deleted
                      		if attached root.getRight as okNode then
								root.setValue(okNode.getValue)
							end

                    	--change the tree
                    		tmpNode := root.getRight;
                    		if attached root.getLeft as okNode then
								root.setright(okNode.getRight)
							end
						--delete the storage place
                    		--free(tmpNode);

                  		else
                  			--smallest child found
                 		 	if attached root.getLeft as okNode then
								root.setValue(okNode.getValue)
							end
                  		end
                	end
                end
 			end
		end
	end
end

