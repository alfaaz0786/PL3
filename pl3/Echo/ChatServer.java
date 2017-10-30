import java.io.*;
import java.net.*;
import java.util.*;
 
public class ChatServer implements Runnable
{
    Socket csocket;
     
    public ChatServer(Socket csocket) 
    {
    this.csocket = csocket;
    }
     
    public static void main(String args[]) throws Exception 
    {
    ServerSocket ssock = null;
 
    try
        {
        ssock = new ServerSocket(1234);
        System.out.println("Echo Server Listening....");
        int i = 1;
         
        while (true) 
            {
            Socket sock = ssock.accept();
            System.out.println("Connected");
            Runnable r = new ChatServer(sock);
            Thread t = new Thread(r);
            t.start();
            System.out.println("Spawning Thread " + i);
            i++;
            }
        }
    catch(Exception e)
        {
        e.printStackTrace();
        }
 
    }
     
    public void run() 
    {
    System.out.println("Inside run");
    try
        {
        try
            {
            //store the input and output streams of the incoming socket
            InputStream  is  = csocket.getInputStream();
            OutputStream os  = csocket.getOutputStream();
             
            //create a Scanner object to read the client messages
            Scanner in  = new Scanner(is);
            //create a PrintWriter to send the client messages
            PrintWriter out = new PrintWriter(os, true /* autoflush */);
             
            out.println("Hello from EchoServer!!!, enter BYE to exit.");
 
            //read client input
            boolean done = false;
            while(!done && in.hasNextLine())
                {
                String line = in.nextLine();
                out.println("Echo: "  + line);
                if(line.trim().equals("BYE")) 
                done = true;
                }
            }
        finally
            {
            csocket.close();
            }
    } 
     
    catch (IOException ioe) 
    {
        System.out.println(ioe);
    }
       }
}

----------------------------------------------------------------------------------------------------
OUTPUT:
C:\Program Files\Java\jdk1.6.0_02\bin>javac ChatServer.java
C:\Program Files\Java\jdk1.6.0_02\bin>java ChatServer
Echo Server Listening....
Connected....!
Thread 1
Inside run
Hello from EchoServer!!!, enter BYE to exit.
Echo: hi
Echo: this is shweta
Echo: BYE
