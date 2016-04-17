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
        //**.mgmt.numChannels = 5;

        //@display("bgb=799,698");
        @display("bgb=800, 800");
    submodules:
        configurator: FlatNetworkConfigurator6 {
            parameters:
                @display("p=753,53");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=753,123");
        }
        Home_Agent: HomeAgent6 {
            parameters:
                @display("p=250,325;i=abstract/router");
        }
        Foreign_Agent: Router6 {
            parameters:
                @display("p=550,325");
        }
        Router: Router6 {
            parameters:
                @display("p=400,450");
        }
        MN[total_mn]: WirelessHost6 {
            parameters:
                @display("p=127,189");
        }
        CN[total_cn]: CorrespondentNode6 {
            @display("p=400,650");
        }
        AP_Home: AccessPoint {
            parameters:
                @display("p=250,250;i=device/accesspoint_s;r=200");
        }
        AP_Foreign: AccessPoint {
            parameters:
                @display("p=550,250;i=device/accesspoint_s;r=200");
        }
        hub: EtherHub {
            parameters:
                @display("p=400,500;i=device/hub_s");
        }
    connections allowunconnected:

        Foreign_Agent.ethg++ <--> ethernetline <--> Router.ethg++;
        Home_Agent.ethg++ <--> ethernetline <--> Router.ethg++;

        for i=0..total_cn-1 {
            CN[i].ethg$o++ --> ethernetline --> hub.ethg$i++;
            CN[i].ethg$i++ <-- ethernetline <-- hub.ethg$o++;
        }

        hub.ethg++ <--> ethernetline <--> Router.ethg++;
        AP_Home.ethg$o++ --> ethernetline --> Home_Agent.ethg$i++;
        AP_Home.ethg$i++ <-- ethernetline <-- Home_Agent.ethg$o++;
        AP_Foreign.ethg++ <--> ethernetline <--> Foreign_Agent.ethg++;

}

