using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Eiven.SinglePattern
{
	public class Config
	{
		private Config()
		{

		}

		private static Config config = null;
		public static Config GetConfig()
		{
			if (config == null)
				config = new Config();
			return config;
		}

		//以下是Config类的中配置属性的示例
		public string WorkPath
		{
			get { return Convert.ToString(Application.UserAppDataRegistry.GetValue("WorkPath", Application.StartupPath)); }
			set { Application.UserAppDataRegistry.SetValue("WorkPath", value); }
		}

		public int MaxCount
		{
			get { return Convert.ToInt32(Application.UserAppDataRegistry.GetValue("MaxCount", 100)); }
			set { Application.UserAppDataRegistry.SetValue("MaxCount", value); }
		}

		//...........
	}


}
