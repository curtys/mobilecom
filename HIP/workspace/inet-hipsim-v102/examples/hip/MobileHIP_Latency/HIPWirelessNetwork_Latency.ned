//*********************************************************************************
// File:           HIPWirelessNetwork_Latency.ned
//
// Authors:        Laszlo Tamas Zeke, Laszlo Bokor
//
// Copyright: (C) 2008-2009 BME-HT (Department of Telecommunications,
// Budapest University of Technology and Economics), Budapest, Hungary
//
// Copyright (C) 2007 Faqir Zarrar Yousaf
// Communication Networks Institute
// University of Dortmund, Germany
// faqir.yousaf@uni-dortmund.de
//
// Copyright (C) 2004 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
//**********************************************************************************
// Part of: HIPSim++ Host Identity Protocol Simulation Framework developed by BME-HT
//**********************************************************************************


package inet.examples.hip.MobileHIP_Latency;

import inet.nodes.xmipv6.HomeAgent6;
import inet.nodes.ethernet.EtherSwitch;
import inet.networklayer.autorouting.FlatNetworkConfigurator6;
import inet.nodes.wireless.WirelessAPWithEth;
import inet.nodes.ipv6.Router6;
import inet.nodes.hip.HipHost6;
import inet.nodes.hip.WirelessHipHost6;
import inet.nodes.hip.RvsHost6;
import inet.nodes.ipv6.StandardHost6;
import inet.world.ChannelControl;

channel fiberline extends ned.DatarateChannel
{
    parameters:
        delay = 1us;
        datarate = 512*1000000;
}

channel ethernetline extends ned.DatarateChannel
{
    parameters:
        delay = 0.1us;
}


network HIPWirelessNetwork_Latency
{
    parameters:
        double playgroundSizeX;
        double playgroundSizeY;

    submodules:
        configurator: FlatNetworkConfigurator6 {
            parameters:
                @display("p=763,53;i=block/cogwheel");
        }
        channelcontrol: ChannelControl {
            parameters:
                playgroundSizeX = playgroundSizeX;
                playgroundSizeY = playgroundSizeY;
                numChannels = 5;
                @display("p=753,123;i=misc/sun");
        }
        R_3: Router6 {
            parameters:
                @display("p=277,240;i=abstract/router");
        }
        R_1: Router6 {
            parameters:
                @display("p=566,227;i=abstract/router");
        }
        R_2: Router6 {
            parameters:
                @display("p=406,355;i=abstract/router");
        }
        hipsrv: HipHost6 {
            parameters:
                @display("i=device/pc2;p=406,470");
        }
        dnssrv: StandardHost6 {
            parameters:
                @display("i=device/server_l;p=566,439");
        }
        rvs: RvsHost6 {
            parameters:
                @display("i=device/server_l;p=259,439");
        }
        AP_Home: WirelessAPWithEth {
            parameters:
                @display("p=259,172;i=device/accesspoint_s;r=200");
        }
        AP_1: WirelessAPWithEth {
            parameters:
                @display("p=566,172;i=device/accesspoint_s;r=200");
        }
        switch: EtherSwitch {
            parameters:
                @display("p=406,412;i=device/switch_s");
        }
        mobilehiphost: WirelessHipHost6 {
            @display("p=33,165;i=device/wifilaptop");
        }
    connections allowunconnected:

                         //Home_Agent.ethOut++ --> ethernetline --> R_1.ethIn++;
                         //Home_Agent.ethIn++ <-- ethernetline <-- R_1.ethOut++;

        R_1.ethg++ <--> ethernetline <--> R_2.ethg++;

                                                       //R_2.ethOut++ --> ethernetline --> R_3.ethIn++;
                                                       //R_2.ethIn++ <-- ethernetline <-- R_3.ethOut++;

        R_3.ethg++ <--> ethernetline <--> R_2.ethg++;

        hipsrv.ethg++ <--> ethernetline <--> switch.ethg++;

        dnssrv.ethg++ <--> ethernetline <--> switch.ethg++;

        rvs.ethg++ <--> ethernetline <--> switch.ethg++;

        switch.ethg++ <--> ethernetline <--> R_2.ethg++;

                                                    //R_1.ethOut++ --> ethernetline --> CN.ethIn++;
                                                    //R_1.ethIn++ <-- ethernetline <-- CN.ethOut++;

        AP_Home.ethg++ <--> ethernetline <--> R_3.ethg++;

        AP_1.ethg++ <--> ethernetline <--> R_1.ethg++;

                                                        //AP_2.ethOut++ --> ethernetline --> R_2.ethIn++;
                                                        //AP_2.ethIn++ <-- ethernetline <-- R_2.ethOut++;

                                                        //AP_3.ethOut++ --> ethernetline --> R_3.ethIn++;
                                                        //AP_3.ethIn++ <-- ethernetline <-- R_3.ethOut++;

}


