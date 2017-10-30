import java.io.*;
import java.net.*;
import java.util.*;

public class ChatClient
{
    public ChatClient()
    {
     
    }
     
    public static void main(String args[])
    {
    Socket  clientSocket = null;
    InputStream  is  = null;
    OutputStream  os  = null;
    try
        {
           clientSocket = new Socket("localhost", 80);   //create a socket
            try
              {
            os = clientSocket.getOutputStream();
            is = clientSocket.getInputStream();
            Scanner in = new Scanner(is);
            PrintWriter out  = new PrintWriter(os, true );
            Scanner userIn = new Scanner(System.in);
 
            String userLine = "";
            System.out.println("Enter data to send to the server:-");
            while(userIn.hasNextLine())
                {
                userLine = userIn.nextLine();
                out.println(userLine);
                //out.flush();
                }
             
             while(in.hasNextLine())
                  {
                     String line = in.nextLine();
                     System.out.println(line);
                   }
             }
        finally
            {
            clientSocket.close();
            }
         
        }
    catch(IOException e)
        {
        System.out.println("ERROR>>Couldn't connect to server");
        }
      }
   }

---------------------------------------------------------------------------------------------------------------------
OUTPUT:

C:\Program Files\Java\jdk1.6.0_02\bin>javac ChatClient.java
C:\Program Files\Java\jdk1.6.0_02\bin>java ChatClient
Enter data to send to the server:-
hi
this is shweta
BYE

C:\Program Files\Java\jdk1.6.0_02\bin>