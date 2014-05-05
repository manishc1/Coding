#http://sandrasi-sw.blogspot.com/2012/12/the-skyline-problem.html

"""
You are to design a program to assist an architect in drawing the skyline of a city given the locations of the buildings in the city. To make the problem tractable, all buildings are rectangular in shape and they share a common bottom (the city they are built in is very flat). The city is also viewed as two-dimensional. A building is specified by an ordered triple (Li, Hi, Ri) where Li and Ri are left and right coordinates, respectively, of building i and Hi is the height of the building.

The output should consist of the vector that describes the skyline as shown in the example above. In the skyline vector (v1, v2, v3, ... vn) , the vi such that i is an even number represent a horizontal line (height). The vi such that i is an odd number represent a vertical line (x-coordinate). The skyline vector should represent the "path" taken, for example, by a bug starting at the minimum x-coordinate and traveling horizontally and vertically over all the lines that define the skyline. Thus the last entry in the skyline vector will be a 0. The coordinates must be separated by a blank space.
 """

B=[[1,11,5],[2,6,7],[3,13,9],[12,7,16],[14,3,25],[19,18,22],[23,13,29],[24,4,28]]

# Solution.

R=range
v=[0 for e in R(max([y[2] for y in B])+1)]
for b in B:
   for x in R(b[0], b[2]):
      if b[1]>v[x]:
         v[x]=b[1]
p=1
k=0
for x in R(len(v)):
   V=v[x]
   if p and V==0:
      continue
   elif V!=k:
      p=0
      print "%s %s" % (str(x), str(V)),
   k=V

#----------------------------------
# Induction method

case class Building(left: Int, right: Int, height: Int) {

  require(left <= right, "left must not be greater than right")
  require(height >= 0, "height must be non-negative")
}

case class Point(x: Int, height: Int)

object Skyline {

  def apply(buildings: Building*): Skyline = new Skyline(
    buildings.foldLeft(List.empty[Point]) { (points: List[Point], b: Building) =>
      mergePoints(List(Point(b.left, b.height), Point(b.right, 0)), points, 0, 0, 0, ListBuffer.empty[Point])
    }
  )

  @tailrec private def mergePoints(p1: List[Point], p2: List[Point], prevHgt1: Int, prevHgt2: Int, currHgt: Int, res: ListBuffer[Point]): List[Point] = if (p2.isEmpty) {
    (res ++= p1).toList
  } else if (p1.isEmpty) {
    (res ++= p2).toList
  } else {
    val (firstPt1, firstPt2) = (p1.head, p2.head)
    val (hgt1, hgt2) = if (firstPt1.x == firstPt2.x) (firstPt1.height, firstPt2.height) else if (firstPt1.x < firstPt2.x) (firstPt1.height, prevHgt2) else (prevHgt1, firstPt2.height)
    val maxHgt = math.max(hgt1, hgt2)
    val (points1, points2) = if (firstPt1.x == firstPt2.x) (p1.tail, p2.tail) else if (firstPt1.x < firstPt2.x) (p1.tail, p2) else (p1, p2.tail)
    mergePoints(points1, points2, hgt1, hgt2, maxHgt, if (maxHgt != currHgt) res += (Point(math.min(firstPt1.x, firstPt2.x), maxHgt)) else res)
  }
}


#---------------------------------
# Divide and Conquer

private def apply(buildings: Building*): Skyline = {
  def toSkyline(from: Int, to: Int): List[Point] =
    if (to - from == 1) List(Point(buildings(from).left, buildings(from).height), Point(buildings(from).right, 0))
    else {
      val middle = (from + to) / 2
      mergePoints(toSkyline(from, middle), toSkyline(middle, to), 0, 0, 0, ListBuffer.empty[Point])
    }

  new Skyline(if (buildings.length == 0) List.empty else toSkyline(0, buildings.length))
}
