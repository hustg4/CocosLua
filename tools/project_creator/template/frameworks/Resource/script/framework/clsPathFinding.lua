--[[
  description:横版地图的寻路算法
  author:cokey
  date:2013/07/30
--]]
clsPathNode={}
clsPathNode.__index=clsPathNode

clsPathNode.x=nil
clsPathNode.y=nil
clsPathNode.lineX1=nil
clsPathNode.lineY1=nil
clsPathNode.lineX2=nil
clsPathNode.lineY2=nil

-- 构造
function clsPathNode:new(x,y,lineX1,lineY1,lineX2,lineY2)
  local self={}
  setmetatable(self,clsPathNode)
  self.x=x
  self.y=y
  self.lineX1=lineX1
  self.lineY1=lineY1
  self.lineX2=lineX2
  self.lineY2=lineY2
  return self
end

--结构定义
clsPathFinding={}
clsPathFinding.__index=clsPathFinding

--碰撞线数组(必须为偶数数目)
clsPathFinding.collisionArray=nil
clsPathFinding.mapWidth=nil
clsPathFinding.mapHeight=nil

--构造
function clsPathFinding:new(collisionArray,mapWidth,mapHeight)
  local self={}
  setmetatable(self,clsPathFinding)
  self.collisionArray=collisionArray
  self.mapWidth=mapWidth
  self.mapHeight=mapHeight
  return self
end

--搜索从起点到终点的最短可通行路径
function clsPathFinding:searchPath(startCol,startRow,endCol,endRow)
  local pathPoints={}
  --计算连接起始点到终点形成线段与碰撞线之间的交点
  local intersectionPoints=self:calculateIntersections(startCol,startRow,endCol,endRow)
  local intersectionPointsCount=#intersectionPoints
  if intersectionPointsCount==0 then
    --如果没有交点,则直接返回终点坐标即可
    --print("与碰撞线无交点")
    table.insert(pathPoints,endCol)
    table.insert(pathPoints,endRow)
  elseif intersectionPointsCount==1 then
    local firstIntersectionPoint=intersectionPoints[1]
    table.insert(pathPoints,firstIntersectionPoint.x)
    table.insert(pathPoints,firstIntersectionPoint.y)
  else
    --假如交点数大于1
	local firstIntersectionPoint=intersectionPoints[1]
	local lastIntersectionPoint=intersectionPoints[intersectionPointsCount]
	  
	local d1=(firstIntersectionPoint.x-endCol)*(firstIntersectionPoint.x-endCol)+(firstIntersectionPoint.y-endRow)*(firstIntersectionPoint.y-endRow)
	local d2=(lastIntersectionPoint.x-endCol)*(lastIntersectionPoint.x-endCol)+(lastIntersectionPoint.y-endRow)*(lastIntersectionPoint.y-endRow)
	  
	if d1>d2 then
	  --将第一个交点加入队列
	  table.insert(pathPoints,firstIntersectionPoint.x)
      table.insert(pathPoints,firstIntersectionPoint.y)
	  --print("加入第一个交点:("..firstIntersectionPoint.x.."x"..firstIntersectionPoint.y..")")

      --加入首末交点之间的碰撞线折点
	  local collisionArrayCount=table.getn(self.collisionArray)
	  local startAdd=false
      for i=1,collisionArrayCount-3,2 do
        local x1=self.collisionArray[i]
        local y1=self.collisionArray[i+1]
        local x2=self.collisionArray[i+2]
        local y2=self.collisionArray[i+3]
        if firstIntersectionPoint.lineX2==x2 and firstIntersectionPoint.lineY2==y2 then
          startAdd=true
        end
        if lastIntersectionPoint.lineX1==x1 and lastIntersectionPoint.lineY1==y1 then
          startAdd=false
        end
        if startAdd then
          table.insert(pathPoints,x2)
          table.insert(pathPoints,y2)
          --print("加入折点:("..x2.."x"..y2..")")
        end
      end
      --将最后一个交点加入队列
      table.insert(pathPoints,lastIntersectionPoint.x)
      table.insert(pathPoints,lastIntersectionPoint.y)
      --print("加入最后一个交点:("..lastIntersectionPoint.x.."x"..lastIntersectionPoint.y..")")
    else
      --将第一个交点加入队列
	  table.insert(pathPoints,lastIntersectionPoint.x)
      table.insert(pathPoints,lastIntersectionPoint.y)
	  --print("加入第一个交点:("..lastIntersectionPoint.x.."x"..lastIntersectionPoint.y..")")

      --加入首末交点之间的碰撞线折点
	  local collisionArrayCount=table.getn(self.collisionArray)
	  local startAdd=false
      for i=collisionArrayCount-3,1,-2 do
        local x1=self.collisionArray[i]
        local y1=self.collisionArray[i+1]
        local x2=self.collisionArray[i+2]
        local y2=self.collisionArray[i+3]
        if lastIntersectionPoint.lineX1==x1 and lastIntersectionPoint.lineY1==y1 then
          startAdd=true
        end
        if firstIntersectionPoint.lineX2==x2 and firstIntersectionPoint.lineY2==y2 then
          startAdd=false
        end
        if startAdd then
          table.insert(pathPoints,x1)
          table.insert(pathPoints,y1)
          --print("加入折点:("..x1.."x"..y1..")")
        end
      end
      --将最后一个交点加入队列
      table.insert(pathPoints,firstIntersectionPoint.x)
      table.insert(pathPoints,firstIntersectionPoint.y)
      --print("加入最后一个交点:("..firstIntersectionPoint.x.."x"..firstIntersectionPoint.y..")")
	end
    if intersectionPointsCount%2==0 then
	  --若交点总数是偶数，说明终点在可通行区域内，且中间有障碍
	  --print("交点数为偶数:"..intersectionPointsCount)
      --将终点加入队列
      table.insert(pathPoints,endCol)
      table.insert(pathPoints,endRow)
      --print("加入终点:("..endCol.."x"..endRow..")")
    else
      --若交点总数是奇数，说明终点在不可通行区域内，且中间有障碍
      --print("交点数为奇数:"..intersectionPointsCount)
    end
  end
  return pathPoints
end

--计算两点形成线段与单条碰撞线之间的交点坐标(x1,y1,x2,y2为碰撞线上的点)
function clsPathFinding:calculateIntersection(x1,y1,x2,y2,x3,y3,x4,y4)
  --算法来源：http://rd.189works.com/article-80421-2.html
  
  --三角形abc 面积的2倍
  local area_abc = (x1 - x3) * (y2 - y3) - (y1 - y3) * (x2 - x3)
  --三角形abd 面积的2倍    
  local area_abd = (x1 - x4) * (y2 - y4) - (y1 - y4) * (x2 - x4)
  --面积符号相同则两点在线段同侧,不相交 (对点在线段上的情况,本例当作不相交处理);
  if area_abc * area_abd >= 0 then
    return nil
  end
    
  --三角形cda 面积的2倍    
  local area_cda = (x3 - x1) * (y4 - y1) - (y3 - y1) * (x4 - x1) 
  --三角形cdb 面积的2倍    
  --注意: 这里有一个小优化.不需要再用公式计算面积,而是通过已知的三个面积加减得出.    
  local area_cdb = area_cda + area_abc - area_abd   
  if area_cda * area_cdb >= 0 then   
    return nil
  end 

  --计算交点坐标    
  local t = area_cda / ( area_abd- area_abc )
  local dx= t*(x2 - x1)    
  local dy= t*(y2 - y1)
  local node=clsPathNode:new(x1+dx,y1+dy,x1,y1,x2,y2)
  return node
end

--计算两点形成线段与碰撞线之间的全部交点坐标
function clsPathFinding:calculateIntersections(startCol,startRow,endCol,endRow)
  local intersectionPoints={}
  local collisionArrayCount=table.getn(self.collisionArray)
  if collisionArrayCount<4 then
    return intersectionPoints
  end
  for i=1,collisionArrayCount-3,2 do
    local x1=self.collisionArray[i]
    local y1=self.collisionArray[i+1]
    local x2=self.collisionArray[i+2]
    local y2=self.collisionArray[i+3]
    local intersectionPoint=self:calculateIntersection(x1,y1,x2,y2,startCol,startRow,endCol,endRow)
    --没有交点或者交点为碰撞线的折点，则不加入交点列表
    if intersectionPoint and not self:isInCollisionLineTurningPoint(intersectionPoint.x,intersectionPoint.y) then
      intersectionPoints.insert(intersectionPoint)
    end
  end
  return intersectionPoints
end

--检测某个点是否在碰撞区域内（通过检测地图左下角点与该点的连线与碰撞线交点个数若为奇数，则说明该点在碰撞区域内）
function clsPathFinding:isInCollisionArea(x,y)
  if not self:isInCollisionLine(x,y) then
    local intersectionPoints=self:calculateIntersections(0,self.mapHeight,x,y)
    local intersectionPointsCount=#intersectionPoints
    if intersectionPointsCount%2~=0 then
      return true
    end
  end
  return false
end

--检测某个点是否在碰撞线上
function clsPathFinding:isInCollisionLine(x,y)
  local collisionArrayCount=table.getn(self.collisionArray)
  if collisionArrayCount<4 then
    return false
  end
  for i=1,collisionArrayCount-3,2 do
    local x1=self.collisionArray[i]
    local y1=self.collisionArray[i+1]
    local x2=self.collisionArray[i+2]
    local y2=self.collisionArray[i+3]
    local area_abd = (x1 - x) * (y2 - y) - (y1 - y) * (x2 - x)
    if area_abd==0 then
      return true
    end
  end
  return false
end

--检测某个点是否为碰撞线的折点
function clsPathFinding:isInCollisionLineTurningPoint(x,y)
  local collisionArrayCount=table.getn(self.collisionArray)
  if collisionArrayCount<4 then
    return false
  end
  for i=1,collisionArrayCount-3,2 do
    local x1=self.collisionArray[i]
    local y1=self.collisionArray[i+1]
    local x2=self.collisionArray[i+2]
    local y2=self.collisionArray[i+3]
    if x==x1 and y==y1 or x==x2 and y==y2 then
      return true
    end
  end
  return false
end
