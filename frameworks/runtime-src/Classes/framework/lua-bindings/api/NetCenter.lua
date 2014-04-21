
--------------------------------
-- @module NetCenter
-- @extend Ref

--------------------------------
-- @function [parent=#NetCenter] addNetService 
-- @param self
-- @param #string str
-- @param #NetService netservice
        
--------------------------------
-- @function [parent=#NetCenter] removeAllNetFilters 
-- @param self
        
--------------------------------
-- @function [parent=#NetCenter] dispatchSuccessfulMessage 
-- @param self
-- @param #NetResponse netresponse
        
--------------------------------
-- @function [parent=#NetCenter] removeNetProtocol 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#NetCenter] removeNetProtocolForNetService 
-- @param self
-- @param #string str
        
--------------------------------
-- @function [parent=#NetCenter] removeNetFilter 
-- @param self
-- @param #NetFilter netfilter
        
--------------------------------
-- @function [parent=#NetCenter] removeNetService 
-- @param self
-- @param #string str
        
--------------------------------
-- overload function: addNetProtocol(NetProtocol)
--          
-- overload function: addNetProtocol(string, string, NetHandler)
--          
-- @function [parent=#NetCenter] addNetProtocol
-- @param self
-- @param #string str
-- @param #string str
-- @param #NetHandler nethandler

--------------------------------
-- @function [parent=#NetCenter] sendMessage 
-- @param self
-- @param #NetRequest netrequest
        
--------------------------------
-- @function [parent=#NetCenter] dispatchFailedMessage 
-- @param self
-- @param #NetResponse netresponse
        
--------------------------------
-- @function [parent=#NetCenter] addNetFilter 
-- @param self
-- @param #NetFilter netfilter
        
--------------------------------
-- @function [parent=#NetCenter] sendCommand 
-- @param self
-- @param #string str
-- @param #string str
-- @param #cc.Ref ref
        
--------------------------------
-- @function [parent=#NetCenter] sharedNetCenter 
-- @param self
-- @return NetCenter#NetCenter ret (return value: NetCenter)
        
return nil
