
--------------------------------
-- @module SQLite
-- @extend Ref

--------------------------------
-- overload function: updateTable(string, cc.__Dictionary, string, string)
--          
-- overload function: updateTable(string, cc.__Dictionary, cc.__Dictionary)
--          
-- @function [parent=#SQLite] updateTable
-- @param self
-- @param #string str
-- @param #cc.__Dictionary __dictionary
-- @param #string str
-- @param #string str
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @function [parent=#SQLite] dropTable 
-- @param self
-- @param #string str
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#SQLite] clearTable 
-- @param self
-- @param #string str
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- overload function: deleteFromTable(string, string, string)
--          
-- overload function: deleteFromTable(string, cc.__Dictionary)
--          
-- @function [parent=#SQLite] deleteFromTable
-- @param self
-- @param #string str
-- @param #string str
-- @param #string str
-- @return bool#bool ret (retunr value: bool)

--------------------------------
-- @function [parent=#SQLite] getRecordCount 
-- @param self
-- @param #string str
-- @return int#int ret (return value: int)
        
--------------------------------
-- @function [parent=#SQLite] createTable 
-- @param self
-- @param #string str
-- @param #cc.__Array __array
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#SQLite] insertIntoTable 
-- @param self
-- @param #string str
-- @param #cc.__Dictionary __dictionary
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#SQLite] getValueTypeName 
-- @param self
-- @param #cc.Ref ref
-- @return char#char ret (return value: char)
        
--------------------------------
-- overload function: selectTable(string, string, string)
--          
-- overload function: selectTable(string, cc.__Dictionary)
--          
-- overload function: selectTable(string, string, cc.__Array)
--          
-- overload function: selectTable(string, string)
--          
-- @function [parent=#SQLite] selectTable
-- @param self
-- @param #string str
-- @param #string str
-- @param #cc.__Array __array
-- @return __Array#__Array ret (retunr value: cc.__Array)

--------------------------------
-- @function [parent=#SQLite] openSQLite 
-- @param self
-- @param #string str
-- @return SQLite#SQLite ret (return value: SQLite)
        
--------------------------------
-- @function [parent=#SQLite] clearConnectionCache 
-- @param self
        
return nil
