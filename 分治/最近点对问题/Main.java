import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static void main(String[] args) throws Exception {
		Point[] points = new Point[5];
//		for (int i = 0; i < points.length; i++) {
//			points[i] = new Point(i, (10) - i * i);
//		}
		points[0] = new Point(1, 2);
		points[1] = new Point(3, 4);
		points[2] = new Point(3, 5);
		points[3] = new Point(5, 6);
		points[4] = new Point(7, 8);
		Pair temp = Pair.getClosestPair(points);
		System.out.println(temp.p1.toString());
		System.out.println(temp.p2.toString());
	}
}

class Pair {
	Point p1;
	Point p2;

	public Pair(Point p1, Point p2) {
		this.p1 = p1;
		this.p2 = p2;
	}
	
	void printPair() {
		System.out.print("(" + p1.getX() + ", " + p1.getY() + ")  ");
		System.out.println("(" + p2.getX() + ", " + p2.getY() + ")  ");
	}
	
	double getDistance() {
		return Math.sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
	}
	
	public static Pair getClosestPair(Point[] points) throws Exception {
		Point[] pointsOrderedOnX = points;
		Point[] pointsOrderedOnY = points;
		Arrays.sort(pointsOrderedOnX);
		Arrays.sort(pointsOrderedOnY, new CompareY());
		return distance(pointsOrderedOnX, 0, points.length - 1, pointsOrderedOnY);
	}
	
	public static Pair distance(Point[] pointsOrderedOnX, int low, int high, Point[] pointsOrderedOnY) throws Exception {
		if (high - low == 1) {
			return new Pair(pointsOrderedOnX[low], pointsOrderedOnX[high]);
		}
		if (high - low == 2) {
			double d = distance(pointsOrderedOnX[low], pointsOrderedOnX[high]);
			double d1 = distance(pointsOrderedOnX[low], pointsOrderedOnX[low + 1]);
			double d2 = distance(pointsOrderedOnX[high - 1], pointsOrderedOnX[high]);
			if (d < d1 && d < d2) {
				return new Pair(pointsOrderedOnX[low], pointsOrderedOnX[high]);
			} else if (d1 < d2) {
				return new Pair(pointsOrderedOnX[low], pointsOrderedOnX[low + 1]);
			} else {
				return new Pair(pointsOrderedOnX[high - 1], pointsOrderedOnX[high]);
			}
		}
		
		int mid = (low + high) / 2;
		
		Pair leftPair = distance(pointsOrderedOnX, low, mid, pointsOrderedOnY);
		Pair rightPair = distance(pointsOrderedOnX, mid + 1, high, pointsOrderedOnY);
		
		double d1 = leftPair.getDistance();
		double d2 = rightPair.getDistance();
		double d = d1<d2?d1:d2;
		
		ArrayList<Point> tempStripL = new ArrayList<Point>();
		ArrayList<Point> tempStripR = new ArrayList<Point>();
		
		for (Point point : pointsOrderedOnY) {
			if (point.getX() <= pointsOrderedOnX[mid].getX()
					&& pointsOrderedOnX[mid].getX() - point.getX() <= d) {
				tempStripL.add(point);
			} else if (point.getX() > pointsOrderedOnX[mid].getX()
					&& point.getX() - pointsOrderedOnX[mid].getX() <= d) {
				tempStripR.add(point);
			}
		}
		
		Pair midPair = null;
		int r = 0;// r is the index in stripR
		for (Point p : tempStripL) {
			
			while (r < tempStripR.size() && tempStripR.get(r).getY() <= p.getY()) r++;
			
			int r1 = r;
			while (r1 < tempStripR.size() && Math.abs(tempStripR.get(r1).getY() - p.getY()) <= d) {
				//Check if (stripR[r1], point) is a possible closest pair
				System.out.println(tempStripR.get(r1).toString());
				System.out.println(p.toString());
				if (distance(p, tempStripR.get(r1)) < d) {
					d = distance(p, tempStripR.get(r1));
					midPair = new Pair(p, tempStripR.get(r1));
				}
				r1++;
			}
		}
		
		if (d < d1 && d < d2) {
			return midPair;
		} else if (d1 < d2) {
			return leftPair;
		} else {
			return rightPair;
		}
	}
	
	public static double distance(Point p1, Point p2) {
		return Math.sqrt((p1.getX() - p1.getX()) * (p1.getX() - p1.getX())
				+ (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
	}
	
	public static double distance(double x1, double y1, double x2, double y2) {
		return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}
	
	
}
class Point implements Comparable<Point> {
	private int x;
	private int y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public int compareTo(Point o) {
		if (this.x == o.x) {
			return this.y - o.y;
		} else {
			return this.x - o.x;
		}
	}
	
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
	public static void printPoints(Point[] points) {
		for (Point point : points) {
			System.out.print("(" + point.getX() + ", " + point.getY() + ")  ");
		}
		System.out.println();
	}
	public static void printPoints(ArrayList<Point> points) {
		for (Point point : points) {
			System.out.print("(" + point.getX() + ", " + point.getY() + ")  ");
		}
		System.out.println();
	}
	@Override
	public String toString() {
		return "(" + this.getX() + ", " + this.getY() + ")";
	};
	
	/** Test Method */
	public static void main(String[] args) {
		Point[] points = new Point[100];
		for (int i = 0; i < points.length; i++) {
			points[i] = new Point((int)(Math.random() * 100),(int)(Math.random() * 100));
		}
		Arrays.sort(points);
		for (int i = 0; i < points.length; i++) {
			System.out.println(points[i].getX() + " " + points[i].getY());
		}
		Arrays.sort(points, new CompareY());
		for (int i = 0; i < points.length; i++) {
			System.out.println(points[i].getX() + " " + points[i].getY());
		}
	}
	
}
class CompareY implements Comparator<Point> {

	@Override
	public int compare(Point o1, Point o2) {
		if (o1.getY() == o2.getY()) {
			return o1.getX() - o2.getX();
		} else {
			return o1.getY() - o2.getY();
		}
	}
}