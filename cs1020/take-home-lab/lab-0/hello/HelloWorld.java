import java.util.*;

public class HelloWorld {
	
	private boolean isTest = false;
	private int firstBit = 0, secondBit = 0, result = 0;
	private Scanner sc = new Scanner(System.in);
	private String operator = "";

	private int readsNumber() {
		int num = sc.nextInt();
		return num;
	}

	private String readsString() {
		String str = sc.next();
		return str;
	}

	private int identifiesResult(String operator, int firstBit, int secondBit) {
		if (operator.equals("AND")) {
			if (firstBit == 1 && secondBit == 1) {
				return 1;
			} else {
				return 0;
			}
		}

		if (operator.equals("OR")) {
			if (firstBit == 0 && secondBit == 0) {
				return 0;
			}
		}

		return 1; // Operator is 'OR' and at least one of firstBit and secondBit is 1
	}

	private void displaysResult(int result) {
		System.out.println(result);
	}

	private void readsInputs() {
		operator = readsString();
		firstBit = readsNumber();
		secondBit = readsNumber();
		if (isTest) {
			System.out.println("Entered: " + operator + " " + firstBit + " " + secondBit);
		}
	}

	// Type 1: Read N operations
	private void processesMethodOne() {
		int N = readsNumber();
		for (int i = 0; i < N; i++) {
			readsInputs();
			result = identifiesResult(operator, firstBit, secondBit);
			displaysResult(result);
		}
	}

	// Type 2: Read until special character '0'
	private void processesMethodTwo() {
		while (true) {
			operator = sc.next();
			if (operator.equals("0")) {
				break;
			}
			firstBit = readsNumber();
			secondBit = readsNumber();
			result = identifiesResult(operator, firstBit, secondBit);
			displaysResult(result);
		}
	}

	// Type 3: Read until end of file
	private void processesMethodThree() {
		while (sc.hasNext()) {
			readsInputs();
			result = identifiesResult(operator, firstBit, secondBit);
			displaysResult(result);
		}
	}

	private void processesResult(int queryType) {
		if (queryType == 1) {
			processesMethodOne();
		}
		if (queryType == 2) {
			processesMethodTwo();
		}
		if (queryType == 3) {
			processesMethodThree();
		}
	}
	private void run() {
		int queryType = readsNumber();
		if (isTest) {
			System.out.println("queryType = " + queryType);
		}
		processesResult(queryType);
	}

	public static void main(String[] args) {
		HelloWorld obj = new HelloWorld();
		obj.run();
	}
}
