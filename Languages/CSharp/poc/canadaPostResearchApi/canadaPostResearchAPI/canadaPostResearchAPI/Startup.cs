using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(canadaPostResearchAPI.Startup))]
namespace canadaPostResearchAPI
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
