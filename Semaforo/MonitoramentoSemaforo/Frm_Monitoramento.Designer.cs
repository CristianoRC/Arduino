namespace MonitoramentoSemaforo
{
    partial class Frm_Monitoramento
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Frm_Monitoramento));
            this.pictureStatus = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btn_Alerta = new System.Windows.Forms.Button();
            this.timerStatusLed = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pictureStatus)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureStatus
            // 
            this.pictureStatus.Image = global::MonitoramentoSemaforo.Properties.Resources.desligado;
            this.pictureStatus.Location = new System.Drawing.Point(12, 3);
            this.pictureStatus.Name = "pictureStatus";
            this.pictureStatus.Size = new System.Drawing.Size(178, 252);
            this.pictureStatus.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureStatus.TabIndex = 0;
            this.pictureStatus.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.panel1.Controls.Add(this.pictureStatus);
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(202, 265);
            this.panel1.TabIndex = 1;
            // 
            // btn_Alerta
            // 
            this.btn_Alerta.FlatAppearance.MouseOverBackColor = System.Drawing.Color.YellowGreen;
            this.btn_Alerta.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_Alerta.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.45F);
            this.btn_Alerta.Location = new System.Drawing.Point(227, 97);
            this.btn_Alerta.Name = "btn_Alerta";
            this.btn_Alerta.Size = new System.Drawing.Size(263, 71);
            this.btn_Alerta.TabIndex = 2;
            this.btn_Alerta.Text = "Ativar alerta";
            this.btn_Alerta.UseVisualStyleBackColor = true;
            this.btn_Alerta.Click += new System.EventHandler(this.btn_Alerta_Click);
            // 
            // timerStatusLed
            // 
            this.timerStatusLed.Enabled = true;
            this.timerStatusLed.Interval = 5000;
            this.timerStatusLed.Tick += new System.EventHandler(this.timerStatusLed_Tick);
            // 
            // Frm_Monitoramento
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(525, 262);
            this.Controls.Add(this.btn_Alerta);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Frm_Monitoramento";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Monitoramento semaforo";
            this.Load += new System.EventHandler(this.Frm_Monitoramento_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureStatus)).EndInit();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureStatus;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btn_Alerta;
        public System.Windows.Forms.Timer timerStatusLed;
    }
}

