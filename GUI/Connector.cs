using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.WebRequestMethods;

namespace GUI
{
    internal class Connector
    {
        public enum Requests
        {
            Error = 100,
            Log_In = 101,
            Sign_Up = 102,
            Log_Out = 103,
            Get_Rooms = 104,
            Get_Players = 105,
            Get_Personal_Stats = 106,
            Get_High_Score = 107,
            Join_Room = 108,
            Create_Room = 109,
            Exit = 200,
            Close_Room = 201,
            Admin_Start_Game = 202,
            Member_Start_Game = 203,
            Room_State = 204,
            Leave_Room = 205,
            Leave_Game = 301,
            Get_Question = 302,
            Submit_Answer = 303,
            Get_Game_Result = 304
        };

        private static TcpClient client = new TcpClient();
        public static bool connected { get; set; }
        public static IPAddress serverIP { get; } = IPAddress.Parse("127.0.0.1");
        public static int serverPort { get; } = 12345;

        static Connector()
        {
            
            IPEndPoint serverEndPoint = new IPEndPoint(serverIP, serverPort);
            try
            {
                client.Connect(serverEndPoint);
            }
            catch
            {
                connected = false;
                return;
            }
            
            connected = true;
        }

        public static bool sendMSG(string msg, int code)
        {
            try
            {
                msg = code.ToString() + msg.Length.ToString() + msg;//protocol
                NetworkStream clientStream = client.GetStream();
                byte[] buffer = new ASCIIEncoding().GetBytes(msg);
                clientStream.Write(buffer, 0, buffer.Length);
                clientStream.Flush();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "Failed to send message to server", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            return true;
        }

        public static string recvMSG()
        {
            try
            {
                NetworkStream clientStream = client.GetStream();
                byte[] buffer = new byte[4096];
                int bytesRead = clientStream.Read(buffer, 0, 4096);
                string msg = Encoding.ASCII.GetString(buffer);
                return msg;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Failed reciving message from server", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return null;
            }
        }

        public static bool statusFromServer()
        {
            string msgFromServer = recvMSG();
            msgFromServer = msgFromServer.Substring(msgFromServer.IndexOf("{"));

            return msgFromServer.Contains('1');
        }
    }
}
