using System;
using System.Drawing;
using System.IO.Ports;

namespace MonitoramentoSemaforo
{
    public static class Semaforo
    {
        private static SerialPort comunicacao = new SerialPort("/dev/ttyACM0", 9600);

        public static void AbrirConexao()
        {
            try
            {
                if (!comunicacao.IsOpen)
                    comunicacao.Open();
            }
            catch (Exception)
            {
                throw;
            }

        }

        public static void AtivarAlerta()
        {
            try
            {
                AbrirConexao();
                comunicacao.WriteLine("ativar");
            }
            catch (Exception)
            {
                throw;
            }
        }

        public static void DesativarAlerta()
        {
            try
            {
                AbrirConexao();
                comunicacao.WriteLine("desativar");

            }
            catch (Exception)
            {
                throw;
            }
        }

        public static String ObterCaminhoImagem()
        {
            AbrirConexao();

            var retornoSerial = comunicacao.ReadLine();

            if (retornoSerial.Contains("3"))
                return "Imagens/amarelo.png";
            else if (retornoSerial.Contains("2"))
                return "Imagens/verde.png";
            else if (retornoSerial.Contains("1"))
                return "Imagens/vermelho.png";
            else if (retornoSerial.Contains(""))
                return "Imagens/desligado.png";
            else
                return "Erro";

        }

        public static String ObterSerial()
        {
            AbrirConexao();

            return comunicacao.ReadLine();
        }
    }
}
