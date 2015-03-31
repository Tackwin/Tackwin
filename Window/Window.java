package fr.tackwin.window;

import static org.lwjgl.glfw.Callbacks.errorCallbackPrint;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

import org.lwjgl.Sys;
import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GLContext;

public class Window{

	private String title;
	
	private int width;
	private int height;
	private long window;
	
	private GLFWErrorCallback errorCall = errorCallbackPrint();
	
	public Window(String title, int width, int height){
		this.title = title;
		
		this.width = width;
		this.height = height;
		
		System.out.println("Lwjgl: " + Sys.getVersion() + "\nGLFW : " + glfwGetVersionString());
	}
	
	public void init(){
		glfwSetErrorCallback(errorCall);
		Input.create();
		
		if (glfwInit() != GL_TRUE){
			System.err.println("(Window.java : init())");
			throw(new IllegalStateException());
		}
		
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		
		window = glfwCreateWindow(width, height, title, 0L, 0L);
		if (window == 0){
			System.err.println("(Window.java : init())");
			throw(new IllegalStateException());
		}
		
		glfwSetKeyCallback(window, Input.INPUT);
		glfwMakeContextCurrent(window);
		glfwShowWindow(window);
		
		GLContext.createFromCurrent();
		glClearColor(0, 0, 0, 1);
	}
	
	public int getWidth(){
		return width;
	} public int getHeight(){
		return height;
	} public long get(){
		return window;
	}
	
}
