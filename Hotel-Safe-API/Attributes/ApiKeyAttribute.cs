using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Filters;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Linq;
using System.Threading.Tasks;

namespace Hotel_Safe_API.Attributes
{
    [AttributeUsage(validOn: AttributeTargets.Class)]
    public class ApiKeyAttribute : Attribute, IAsyncActionFilter
    {
        public async Task OnActionExecutionAsync(ActionExecutingContext context, ActionExecutionDelegate next)
        {
            if (!context.HttpContext.Request.Headers.TryGetValue("X-Api-Key", out var clientSpecifiedApiKey))
            {
                context.Result = new ContentResult()
                {
                    StatusCode = 401,
                    Content = "{\"Error\":\"No Api Key provided\"}",
                    ContentType = "application/json"
                };
                return;
            }


            var appSettings = context.HttpContext.RequestServices.GetRequiredService<IConfiguration>();

            var apiKeys = appSettings.GetSection("ApiKeys").GetChildren().Select(x => x.Value).ToArray();


            if (!apiKeys.Contains<string>(clientSpecifiedApiKey))
            {
                context.Result = new ContentResult()
                {
                    StatusCode = 401,
                    Content = "{\"Error\":\"Api Key not valid\"}",
                    ContentType = "application/json"
                };
                return;
            }

            await next();
        }
    }
}
