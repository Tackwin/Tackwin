public class Convert {

	/**
	 * Return the equivalent second of milliSecond given.
	 * 
	 * @param milliSecond
	 * @return
	 */
	public static float milliToSecond(long milliSecond) {
		return milliSecond / 1000F;
	}

	/**
	 * Return the equivalent second of nanoSecond given.
	 * 
	 * @param nanoTime
	 * @return
	 */
	public static float nanoToSecond(long nanoSecond) {
		return nanoSecond / 1000000000F;
	}

	/**
	 * Return the equivalent milliSecond of second given.
	 * 
	 * @param second
	 * @return
	 */
	public static long secondToMili(float second) {
		return (long) (second * 1000L);
	}

	/**
	 * Return the equivalent nanoSecond of second given.
	 * 
	 * @param second
	 * @return
	 */
	public static long SecondToNano(float second) {
		return (long) (second * 1000000000L);
	}

	/**
	 * Convert a short (16bit) to two byte(8bit) in a array.
	 * 
	 * @param value
	 * @return
	 */
	public static byte[] shortToByte(short value) {
		return new byte[] { (byte) (value), (byte) (value >> 8) };
	}
	/**
	 * Convert a array of two byte(8bit) to a short(16bit).
	 * 
	 * @param value
	 * @return
	 */
	public static short byteToShort(byte[] value) {
		return (short) ((value[0] & 0xFF) + (short) (value[1] << 8));
	}
	/**
	 * Convert a long(64bit) to height byte(8bit) in a array.
	 * 
	 * @param value
	 * @return
	 */
	public static byte[] longToByte(long value) {
		return new byte[] { (byte) (value), (byte) (value >> 8), (byte) (value >> 16)
				, (byte) (value >> 24), (byte) (value >> 32), (byte) (value >> 40)
				, (byte) (value >> 48), (byte) (value >> 56) };
	}
	/**
	 * Convert a array of height byte(8bit) to a long(64bit).
	 * 
	 * @param value
	 * @return
	 */
	public static long byteToLong(byte[] value) {
		return ((long) (value[0] & 0xFF)) + (((long) (value[1] & 0xFF)) << 8) + 
				(((long) (value[2] & 0xFF)) << 16) + (((long) (value[3] & 0xFF)) << 24) + 
				(((long) (value[4] & 0xFF)) << 32) + (((long) (value[5] & 0xFF)) << 40) +
				(((long) (value[6] & 0xFF)) << 48) + (((long) (value[7])) << 56);
	}

}
