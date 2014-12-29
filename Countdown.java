public class Countdown {

	private boolean play = true;

	private long pause = 0;
	private long pauseStart = 0;
	
	private float time;
	private long timer;

	/**
	 * Create a countdown with the specified timer
	 * @param time the specified timer
	 */
	public Countdown(float time) {
		this.time = time;
		this.timer = System.nanoTime();
	}

	/**
	 * Getter of the timer
	 * @return
	 */
	public float getTime() {
		return time;
	}
	/**
	 * Setter of the timer
	 * @param time
	 */
	public void setTime(float time){
		this.time = time;
	}

	/**
	 * @return the percentage (0 to 1) of the time passed by the given time
	 */
	public float getProgress() {
		float value = 0;
		if (play)
			value = (toSecond(timeSince(timer) - pause) / time);
		else
			value = (toSecond(timeSince(timer) - timeSince(pauseStart)) / time);
		value = (value > 1) ? 1 : ((value < 0) ? 0 : value);
		return value;
	}

	/**
	 * Test if the countdown is over and if he is, he restart
	 * @return true if the countdown is over
	 */
	public boolean isOver() {
		if (play) {
			if (time <= toSecond(timeSince(timer) - pause)) {
				restart();
				return true;
			}
		}
		return false;
	}

	/**
	 * Test if the countdown is over. If he is he restart only if restart is true
	 * @param restart
	 * @return
	 */
	public boolean isOver(Boolean restart) {
		if (play) {
			if (time <= toSecond(timeSince(timer) - pause)) {
				if (restart)
					restart();
				return true;
			}
		}
		return false;
	}

	/**
	 * Restart the countdown
	 */
	public void restart() {
		play = true;
		timer = System.nanoTime();
		pause = 0;
		pauseStart = 0;
	}

	/**
	 * Pause the countdown use {@link #resume()} to resume it
	 */
	public void pause() {
		play = false;
		pauseStart = System.nanoTime();
	}

	/**
	 * Resume the countdown if he was in {@link #pause()}
	 */
	public void resume() {
		play = true;
		pause += timeSince(pauseStart);
		pauseStart = 0;
	}

	/**
	 * Stop the countdown use {@link #restart()} to restart him
	 */
	public void stop() {
		play = false;
	}
	
	/**
	 * Compute the time spent since the time given
	 * @param time
	 * @return 
	 */
	private long timeSince(long time){
		return System.nanoTime() - time;
	}
	
	/**
	 * Convert nanoSeconds to Seconds
	 * @param time in nanoSeconds
	 * @return time in Seconds
	 */
	private float toSecond(long time){
		return (float)time / 1000000000f;
	}
}