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


//package inet.examples.mobileipv6;

import inet.linklayer.ethernet.EtherHub;
import inet.networklayer.configurator.ipv6.FlatNetworkConfigurator6;
import inet.node.ethernet.Eth100M;
import inet.node.ipv6.Router6;
import inet.node.wireless.AccessPoint;
import inet.node.xmipv6.CorrespondentNode6;
//import inet.node.xmipv6.ForeignAgent6;
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
        //**.mgmt.numChannels = 5;

        //@display("bgb=799,698");
        @display("bgb=1000, 800");
    submodules:
        configurator: FlatNetworkConfigurator6 {
            parameters:
                @display("p=125.424,583.704");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=125.424,704.304");
        }
        Home_Agent: HomeAgent6 {
            parameters:
                @display("p=482.4,348.936;i=abstract/router");
        }
        Foreign_Agent: Router6 {
            parameters:
                @display("p=783.096,348.936");
        }
        Router: Router6 {
            parameters:
                @display("p=630.336,472.752");
        }
        MN: WirelessHost6 {
            parameters:
                //@display("p=127,189");
                @display("p=171.59999,192.4");
        }
        CN: CorrespondentNode6 {
            @display("p=630.336,673.752");
        }
        AP_Home: AccessPoint {
            parameters:
                @display("p=482.4,273.36002;i=device/accesspoint_s;r=200");
        }
        AP_Foreign: AccessPoint {
            parameters:
                @display("p=783.096,273.36002;i=device/accesspoint_s;r=200");
        }
        hub: EtherHub {
            parameters:
                @display("p=630.336,522.6;i=device/hub_s");
        }
    connections allowunconnected:

        Foreign_Agent.ethg++ <--> ethernetline <--> Router.ethg++;
        Home_Agent.ethg++ <--> ethernetline <--> Router.ethg++;

        CN.ethg++ <--> ethernetline <--> hub.ethg++;

//        for i=0..total_cn-1 {
//            CN[i].ethg$o++ --> ethernetline --> hub.ethg$i++;
//            CN[i].ethg$i++ <-- ethernetline <-- hub.ethg$o++;
//        }

        hub.ethg++ <--> ethernetline <--> Router.ethg++;
        //        AP_Home.ethg$o++ --> ethernetline --> Home_Agent.ethg$i++;
        //        AP_Home.ethg$i++ <-- ethernetline <-- Home_Agent.ethg$o++;
        AP_Home.ethg++ <--> ethernetline <--> Home_Agent.ethg++;
        AP_Foreign.ethg++ <--> ethernetline <--> Foreign_Agent.ethg++;
}

