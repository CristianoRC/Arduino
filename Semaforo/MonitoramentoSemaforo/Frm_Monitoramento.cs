using System;
using System.Drawing;
using System.Windows.Forms;

namespace MonitoramentoSemaforo
{
    public partial class Frm_Monitoramento : Form
    {
        private bool estadoAlerta;

        public Frm_Monitoramento()
        {
            InitializeComponent();

            estadoAlerta = false;
        }

        private void btn_Alerta_Click(object sender, EventArgs e)
        {
            try
            {
                if (!estadoAlerta)
                {
                    Semaforo.AtivarAlerta();

                    btn_Alerta.Text = "Desativar alerta";
                    btn_Alerta.FlatAppearance.MouseOverBackColor = Color.LightSeaGreen;
                    estadoAlerta = true;
                }
                else
                {
                    Semaforo.DesativarAlerta();

                    btn_Alerta.Text = "Ativar alerta";
                    btn_Alerta.FlatAppearance.MouseOverBackColor = Color.GreenYellow;
                    estadoAlerta = false;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ocorreu um erro ao efetuar a comunicação com o semaforo: {ex.Message}",
                                 "Erro!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void timerStatusLed_Tick(object sender, EventArgs e)
        {
            //pictureStatus.ImageLocation = Semaforo.ObterCaminhoImagem();

            //txt_Leitura.Text += $"{DateTime.Now.ToShortTimeString()}: {Semaforo.ObterCaminhoImagem()} {Environment.NewLine}";
        }

        private void Frm_Monitoramento_Load(object sender, EventArgs e)
        {
            try
            {
                Semaforo.AbrirConexao();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ocorreu um erro: {ex.Message}");
            }
        }
    }
}
