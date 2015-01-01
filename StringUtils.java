
public class StringUtils {
	
	/**
	 * Count the number of time the Character c come into the String given. 
	 * @param c
	 * @param string
	 * @return 
	 */
	public static int occurenceOf(char c, String string){
		int occ = 0;
		for (int i = 0; i < string.length(); i++){
			if (string.charAt(i) == c)
				i++;
		}
		return occ;
	}
	
	/**
	 * Return a String format with multiplier ex:
	 * formatNumber(10548, 3) = "10.54K" or,
	 * formatNumber(123456789, 2) = "123.4M"
	 * @param number
	 * @param nNumber
	 * @return
	 */
	public static String formatNumber(double number){
		char n = ' ';
		char[] mult = {'K', 'M', 'B', 'T', 'q', 'Q', 's', 'S', 'O', 'N', 'd', 'U', 'D', '!', '@', '#', '$', '%', '^', '&', '*'};
		for (int i = 0; (float)number/1000 > 1; i++){
			number /= 1000;
			n = mult[i];
		}
		if (number < 10){
			number = ((long)(number * 1000));
			number /= 1000;
		} else if (number < 100){
			number = ((long)(number * 100));
			number /= 100;
		} else {
			number = ((long)(number * 10));
			number /= 10;
		}
		String str = Double.toString(number) + Character.toString(n);
		return str;
	}
	
}
