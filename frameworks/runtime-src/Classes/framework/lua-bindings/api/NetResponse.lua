
--------------------------------
-- @module NetResponse
-- @extend Ref

--------------------------------
-- @function [parent=#NetResponse] setRequest 
-- @param self
-- @param #NetRequest netrequest
        
--------------------------------
-- @function [parent=#NetResponse] setBody 
-- @param self
-- @param #JSONObject jsonobject
        
--------------------------------
-- @function [parent=#NetResponse] getProtocolID 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- @function [parent=#NetResponse] getRequest 
-- @param self
-- @return NetRequest#NetRequest ret (return value: NetRequest)
        
--------------------------------
-- @function [parent=#NetResponse] setProtocolID 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#NetResponse] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#NetResponse] getBody 
-- @param self
-- @return JSONObject#JSONObject ret (return value: JSONObject)
        
--------------------------------
-- overload function: create(string, JSONObject, NetRequest)
--          
-- overload function: create()
--          
-- @function [parent=#NetResponse] create
-- @param self
-- @param #string str
-- @param #JSONObject jsonobject
-- @param #NetRequest netrequest
-- @return NetResponse#NetResponse ret (retunr value: NetResponse)

return nil
