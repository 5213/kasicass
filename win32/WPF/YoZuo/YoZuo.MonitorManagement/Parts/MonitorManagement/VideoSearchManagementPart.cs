﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel.Composition;

using Illusion;
using YoZuo.Workbench;

namespace YoZuo.MonitorManagement
{
	[MenuPart(BaseMenu = MonitorManagementWorkbenchName.MonitorManagementGroup, PreviousMenu = MonitorManagementWorkbenchName.VideoCompressManagementPart)]
	public class VideoSearchManagementPart : MenuPart
	{
		public VideoSearchManagementPart()
			: base(MonitorManagementWorkbenchName.VideoSearchManagementPart)
		{
			Icon = "GrayLarge.png";
		}
	}
}
