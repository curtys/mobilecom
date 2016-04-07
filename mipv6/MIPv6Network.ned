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


package mobilecom.mipv6;

import inet.linklayer.ethernet.EtherHub;
import inet.networklayer.configurator.ipv6.FlatNetworkConfigurator6;
import inet.node.inet.AdhocHost;
import inet.node.ipv6.Router6;
import inet.node.wireless.AccessPoint;
import inet.node.xmipv6.CorrespondentNode6;
import inet.node.xmipv6.HomeAgent6;
import inet.node.xmipv6.WirelessHost6;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;


channel fiberline extends ned.DatarateChannel
{
    parameters:
        delay = 1us;
        datarate = 512Mbps;
}

channel ethernetline extends ned.DatarateChannel
{
    parameters:
        delay = 0.1us;
        datarate = 100Mbps;
}

network mIPv6Network
{
    parameters:
        double total_mn;
        double total_cn;
        **.mgmt.numChannels = 5;

        @display("bgb=1217,788");
    submodules:
        configurator: FlatNetworkConfigurator6 {
            parameters:
                @display("p=1151,39");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=1154,123");
        }
        Home_Agent: HomeAgent6 {
            parameters:
                @display("p=415,266;i=abstract/router");
        }
        Foreign_Agent: Router6 {
            parameters:
                @display("p=708,266");
        }
        R_1: Router6 {
            parameters:
                @display("p=554,364");
        }
        MN: WirelessHost6 {
            parameters:
                @display("p=428,113;i=,white;r=150");
        }
        CN: CorrespondentNode6 {
            @display("p=554,506");
        }
        AP_1: AccessPoint {
            parameters:
                @display("p=708,211;i=device/accesspoint_s;r=200");
        }
        hub: EtherHub {
            parameters:
                @display("p=554,423;i=device/hub_s");
        }
        AP_Home: AccessPoint {
            @display("p=415,205;r=200");
        }
    connections allowunconnected:

                         //Home_Agent.ethOut++ --> ethernetline --> R_1.ethIn++;
                         //Home_Agent.ethIn++ <-- ethernetline <-- R_1.ethOut++;

        Foreign_Agent.ethg++ <--> ethernetline <--> R_1.ethg++;

                                                       //R_2.ethOut++ --> ethernetline --> R_3.ethIn++;
                                                       //R_2.ethIn++ <-- ethernetline <-- R_3.ethOut++;

        hub.ethg++ <--> ethernetline <--> R_1.ethg++;

                                                    //R_1.ethOut++ --> ethernetline --> CN.ethIn++;
                                                    //R_1.ethIn++ <-- ethernetline <-- CN.ethOut++;

        AP_1.ethg++ <--> ethernetline <--> Foreign_Agent.ethg++;

                                                        //AP_2.ethOut++ --> ethernetline --> R_2.ethIn++;
                                                        //AP_2.ethIn++ <-- ethernetline <-- R_2.ethOut++;

                                                        //AP_3.ethOut++ --> ethernetline --> R_3.ethIn++;
                                                        //AP_3.ethIn++ <-- ethernetline <-- R_3.ethOut++;

        Home_Agent.ethg++ <--> AP_Home.ethg++;
        Home_Agent.ethg++ <--> R_1.ethg++;
        hub.ethg++ <--> CN.ethg++;
}

