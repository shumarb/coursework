import java.util.Scanner;

public class Palindrome {

	private boolean isTest = false;

	/**
	 * Function reads input from user
	 * Precon: Input1 and input2 are empty strings
	 * Input1 and input2 are non-empty strings
	 */
	private String[] readsInputs() {
		Scanner sc = new Scanner(System.in);
		String[] inputs = new String[2];
		for (int i = 0; i < inputs.length; i++) {
			inputs[i] = sc.next();
		}
		sc.close();
		return inputs;
	}

	/**
	 * Function determines if the 2 words are a palindrome of one another
	 * Precon: Input1 and input2 are the two inputs that the user has entered
	 * Postcon: Input1 and input2 form a palindrome of one another 
	 */
	private boolean comparesInputs(String[] inputs) {
		String input1Rev = "", input1 = inputs[0], input2 = inputs[1];
		
		for (int i = input1.length() - 1; i >= 0; i--) {
			input1Rev += input1.charAt(i);
		}
		if (isTest) {
			System.out.println("Input1 = " + input1 + ", input2 = " + input2 + ", input1Rev = " + input1Rev);
		}
		return input1Rev.equals(input2);
	}

	/**
	 * Function displays result of comparison of input1 and input2
	 * Precon: Input1 is a palindrome of input2
	 * Postcon: Nil
	 */
	private void displaysResult(boolean isPalindrome) {
		if (isPalindrome) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

	private void run() {
		String inputs[] = readsInputs();
		boolean isPalindrome = comparesInputs(inputs);
		displaysResult(isPalindrome);
	}

	public static void main(String[] args) {
		Palindrome obj = new Palindrome();
		obj.run();
	}
}

