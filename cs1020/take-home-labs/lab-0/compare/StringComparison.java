import java.util.Scanner;

public class StringComparison {
	
	private boolean isTest = false;
	private Scanner sc = new Scanner(System.in);
	
	private String readsString() {
		String input = sc.nextLine();
		return input.toLowerCase();
	}
	
	private int comparesStrings(String input1, String input2) {
		sc.close();
		if (isTest) {
			System.out.println("input1: " + input1 + ", input2: " + input2);
		}
		return input1.compareTo(input2);
	}

	private void displaysResult(int result) {
		// Input1 is lexicographically bigger than input2
		if (result < 0) {
			System.out.println("1");
		} else if (result > 0) {
			System.out.println("2");
		} else {
			System.out.println("0");
		}
	}
	private void run() {
		String input1 = readsString();
		String input2 = readsString();
		int result = comparesStrings(input1, input2);
		displaysResult(result);
	}

	public static void main(String[] args) {
		StringComparison obj = new StringComparison();
		obj.run();
	}
}
