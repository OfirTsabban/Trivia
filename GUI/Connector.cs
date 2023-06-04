using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace GUI
{
    internal class Connector
    {
        public static bool connected { get; set; }
        public static IPAddress serverIP { get; } = IPAddress.Parse("127.0.0.1");
        public static int serverPort { get; } = 12345;

        static Connector()
        {
            TcpClient client = new TcpClient();
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
    }
}
