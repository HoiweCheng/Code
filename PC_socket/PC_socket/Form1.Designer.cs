namespace PC_socket
{
    partial class iwinRobot
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.IPTextBox = new System.Windows.Forms.TextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.PortTextBox = new System.Windows.Forms.TextBox();
            this.RecordTextBox = new System.Windows.Forms.TextBox();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.CommandTextBox = new System.Windows.Forms.TextBox();
            this.SendButton = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // IPTextBox
            // 
            this.IPTextBox.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.IPTextBox.Location = new System.Drawing.Point(522, 26);
            this.IPTextBox.Name = "IPTextBox";
            this.IPTextBox.Size = new System.Drawing.Size(100, 21);
            this.IPTextBox.TabIndex = 0;
            this.IPTextBox.Text = "ip address";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // PortTextBox
            // 
            this.PortTextBox.Location = new System.Drawing.Point(523, 62);
            this.PortTextBox.Name = "PortTextBox";
            this.PortTextBox.Size = new System.Drawing.Size(100, 21);
            this.PortTextBox.TabIndex = 2;
            this.PortTextBox.Text = "port";
            // 
            // RecordTextBox
            // 
            this.RecordTextBox.Location = new System.Drawing.Point(12, 26);
            this.RecordTextBox.Multiline = true;
            this.RecordTextBox.Name = "RecordTextBox";
            this.RecordTextBox.ReadOnly = true;
            this.RecordTextBox.Size = new System.Drawing.Size(503, 192);
            this.RecordTextBox.TabIndex = 3;
            // 
            // ConnectButton
            // 
            this.ConnectButton.Location = new System.Drawing.Point(524, 99);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(99, 23);
            this.ConnectButton.TabIndex = 4;
            this.ConnectButton.Text = "连接";
            this.ConnectButton.UseVisualStyleBackColor = true;
            this.ConnectButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // CommandTextBox
            // 
            this.CommandTextBox.Location = new System.Drawing.Point(12, 241);
            this.CommandTextBox.Name = "CommandTextBox";
            this.CommandTextBox.Size = new System.Drawing.Size(503, 21);
            this.CommandTextBox.TabIndex = 5;
            // 
            // SendButton
            // 
            this.SendButton.Location = new System.Drawing.Point(523, 241);
            this.SendButton.Name = "SendButton";
            this.SendButton.Size = new System.Drawing.Size(89, 23);
            this.SendButton.TabIndex = 6;
            this.SendButton.Text = "发送";
            this.SendButton.UseVisualStyleBackColor = true;
            this.SendButton.Click += new System.EventHandler(this.SendButton_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(524, 174);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(88, 23);
            this.button2.TabIndex = 8;
            this.button2.Text = "button2";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // iwinRobot
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(624, 305);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.SendButton);
            this.Controls.Add(this.CommandTextBox);
            this.Controls.Add(this.ConnectButton);
            this.Controls.Add(this.RecordTextBox);
            this.Controls.Add(this.PortTextBox);
            this.Controls.Add(this.IPTextBox);
            this.Name = "iwinRobot";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox IPTextBox;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.TextBox PortTextBox;
        private System.Windows.Forms.TextBox RecordTextBox;
        private System.Windows.Forms.Button ConnectButton;
        private System.Windows.Forms.TextBox CommandTextBox;
        private System.Windows.Forms.Button SendButton;
        private System.Windows.Forms.Button button2;
    }
}

