class StrongToChar {
	public static void main(String[] args) {

		for (String s : args) {

			try {
				int i = Integer.parseInt(s);
				System.out.println(s + " -> int");
				continue;
			} catch (Exception e) {
			}

			try {
				float f = Float.parseFloat(s);
				System.out.println(s + " -> float");
				continue;
			} catch (Exception e) {
			}

			if (s.length() == 1) {
				char c = s.charAt(0);
				System.out.println(s + " -> char");
			} else {
				System.out.println(s + " -> String" + " length:-" + s.length());
			}
		}
		// run this => java Test "😊" "vishal" "વિશાલ"
		// and see output, it not normal

		String s1 = "Java";
		String s2 = "Ja" + "va";
		String s3 = new String("Java");

		System.out.println(s1 == s2);
		System.out.println(s1 == s3);
	}
}