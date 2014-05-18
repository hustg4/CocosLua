
--------------------------------
-- @module SQLite
-- @extend Ref

--------------------------------
-- overload function: updateTable(string, map_table, string, string)
--          
-- overload function: updateTable(string, map_table, map_table)
--          
-- @function [parent=#SQLite] updateTable
-- @param self
-- @param #string str
-- @param #map_table map
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
-- overload function: deleteFromTable(string, map_table)
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
-- @param #array_table array
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @function [parent=#SQLite] insertIntoTable 
-- @param self
-- @param #string str
-- @param #map_table map
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- overload function: selectTable(string, string, string)
--          
-- overload function: selectTable(string, map_table)
--          
-- overload function: selectTable(string, string, array_table)
--          
-- overload function: selectTable(string)
--          
-- @function [parent=#SQLite] selectTable
-- @param self
-- @param #string str
-- @param #string str
-- @param #array_table array
-- @return array_table#array_table ret (retunr value: array_table)

--------------------------------
-- @function [parent=#SQLite] openSQLite 
-- @param self
-- @param #string str
-- @return SQLite#SQLite ret (return value: SQLite)
        
--------------------------------
-- @function [parent=#SQLite] clearConnectionCache 
-- @param self
        
return nil
