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

            switch (retornoSerial)
            {
                case "3":
                    return "Imagens/amarelo.png";
                case "2":
                    return "Imagens/verde.png";
                case "1":
                    return "Imagens/vermelho.png";
                default:
                    return "Imagens/desligado.png";
            }
        }
    }
}
