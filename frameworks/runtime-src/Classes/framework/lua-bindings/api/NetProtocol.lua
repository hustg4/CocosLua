
--------------------------------
-- @module NetProtocol
-- @extend Ref

--------------------------------
-- @function [parent=#NetProtocol] setID 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#NetProtocol] getID 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- @function [parent=#NetProtocol] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#NetProtocol] setServiceID 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#NetProtocol] getServiceID 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- @function [parent=#NetProtocol] getHandler 
-- @param self
-- @return NetHandler#NetHandler ret (return value: NetHandler)
        
--------------------------------
-- @function [parent=#NetProtocol] setHandler 
-- @param self
-- @param #NetHandler nethandler
        
--------------------------------
-- overload function: create(string, string, NetHandler)
--          
-- overload function: create()
--          
-- @function [parent=#NetProtocol] create
-- @param self
-- @param #string str
-- @param #string str
-- @param #NetHandler nethandler
-- @return NetProtocol#NetProtocol ret (retunr value: NetProtocol)

return nil
