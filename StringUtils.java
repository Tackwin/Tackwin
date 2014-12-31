
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
	
}
