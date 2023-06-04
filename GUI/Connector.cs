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

        public static bool sendMSG(string msg)
        {
            try
            {
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
    }
}
